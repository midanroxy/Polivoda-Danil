#include <iostream>
#include <vector>

using namespace std;

class Rect
{
    public:
        float x1,x2,y1,y2;
    public:
        Rect(float x1,float y1,float x2,float y2)
        {
            this->x1 = x1;
            this->x2 = x2;
            this->y1 = y1;
            this->y2 = y2;
        }

        void ToString()
        {
            cout << " : x1: "  << x1 << ", y1: " << y1 << ", x2: " << x2 << ", y2:" << y2 << endl;
        }
};

class RectArray
{
    private:
        vector<Rect*> rectangles;
    public:
        RectArray()
        {


        }

        void AddRectangle(float x1, float y1, float x2, float y2)
        {
            rectangles.push_back(new Rect(x1,y1,x2,y2));
        }

        void ReplaceRectangle(int index, float x, float y)
        {
            if (rectangles.size() <= index)
            {
                cout << "ReplaceRectangle: Incorrect index of rectangle: " << index << endl;
                return;
            }
            rectangles[index]->x1 += x;
            rectangles[index]->x2 += x;
            rectangles[index]->y1 += y;
            rectangles[index]->y2 += y;
        }

        void ResizeRectangle(int index, float width, float height)
        {
            if (rectangles.size() <= index)
            {
                cout << "ResizeRectangle: Incorrect index of rectangle: " << index << endl;
                return;
            }
            if (width <= 0 || height <= 0)
            {
                cout << "ResizeRectangle: Width and height cannot be non-positive numbers" << endl;
                return;
            }
            rectangles[index]->x2 =rectangles[index]->x1 + width;
            rectangles[index]->y2 = rectangles[index]->y1 + height;
        }

        Rect* GetMinRectWithTwoRects(int index1, int index2)
        {
            if (rectangles.size() <= index1 || rectangles.size() <= index2)
            {
                cout << "GetMinRectWithTwoRects: Incorrect index of rectangle" << endl;
                return NULL;
            }
            float minx = 0;
            if (rectangles[index1]-> x1 <= rectangles[index2]->x1)
                minx = rectangles[index1]->x1;
            else
                minx = rectangles[index2]->x1;

            float miny = 0;
            if (rectangles[index1]-> y1 <= rectangles[index2]->y1)
                miny = rectangles[index1]->y1;
            else
                miny = rectangles[index2]->y1;

            float maxx = 0;
            if (rectangles[index1]-> x2 >= rectangles[index2]->x2)
                maxx = rectangles[index1]->x2;
            else
                maxx = rectangles[index2]->x2;

            float maxy = 0;
            if (rectangles[index1]-> y2 >= rectangles[index2]->y2)
                maxy = rectangles[index1]->y2;
            else
                maxy = rectangles[index2]->y2;

            return new Rect(minx, miny, maxx, maxy);
        }

        void Visualize()
        {
            for(int i = 0; i < rectangles.size(); i++)
            {
                cout << "Rect " << i;
                rectangles[i]->ToString();
            }
        }
};

int main()
{
    RectArray* rectArray = new RectArray();

    int currentMenu = 0;
    while(currentMenu != 5)
    {
        cout << "[0]: Add rectangle" << endl;
        cout << "[1]: Visualize rectangles" << endl;
        cout << "[2]: Replace rectangle" << endl;
        cout << "[3]: Resize rectangle" << endl;
        cout << "[4] Get minimal rectangle that contains two rectangles" << endl;
        cout << "[5] Exit" << endl;

        cin >> currentMenu;
        int index = 0;
        switch(currentMenu)
        {
        case 0:
            cout << "Enter coordinates of left down corner of rectangle:" << endl;
            float x1,y1;
            cin >> x1 >> y1;
            cout << "Enter coordinates of right top corner of rectangle:" << endl;
            float x2,y2;
            cin >> x2 >> y2;
            if (x2 <= x1 || y2 <= y1)
                cout << "Wrong coordinates!!!" << endl;
            else
                rectArray->AddRectangle(x1,y1,x2,y2);
            break;
        case 1:
            rectArray->Visualize();
            break;
        case 2:
            cout << "Enter rectangle index:" << endl;
            cin >> index;
            cout << "Enter vector to replace rectangle:" << endl;
            float x,y;
            cin >> x >> y;
            rectArray->ReplaceRectangle(index, x, y);
            break;
        case 3:
            cout << "Enter rectangle index:" << endl;
            cin >> index;
            cout << "Enter width and height:" << endl;
            float width, height;
            cin >> width >> height;
            rectArray->ResizeRectangle(index, width, height);
            break;
        case 4:
            cout << "Enter indexes of two rectangles:" << endl;
            int index1, index2;
            cin >> index1 >> index2;
            Rect* result = rectArray->GetMinRectWithTwoRects(index1, index2);
            if (result != NULL)
                result->ToString();
            break;
        }
    }
    return 0;
}
