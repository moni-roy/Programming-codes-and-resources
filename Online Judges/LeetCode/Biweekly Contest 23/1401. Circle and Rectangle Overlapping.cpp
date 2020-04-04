class Solution
{
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2)
    {
        float xc = (x2 + x1) * 1.0 / 2.0;
        float yc = (y2 + y1) * 1.0 / 2.0;

        float x = fabs(x_center - xc);
        float y = fabs(y_center - yc);

        if (x > (abs(x2 - x1) * 1.0 / 2 + radius))
        {
            return false;
        }
        if (y > (abs(y2 - y1) * 1.0 / 2 + radius))
        {
            return false;
        }

        if (x <= (abs(x2 - x1) * 1.0 / 2))
        {
            return true;
        }
        if (y <= (abs(y2 - y1) * 1.0 / 2))
        {
            return true;
        }

        float cornerDistance_sq = (x - abs(x2 - x1) * 1.0 / 2) * (x - abs(x2 - x1) * 1.0 / 2) +
                                  (y - abs(y2 - y1) * 1.0 / 2) * (y - abs(y2 - y1) * 1.0 / 2);

        return (cornerDistance_sq <= (radius * radius) + .0);
    }
};