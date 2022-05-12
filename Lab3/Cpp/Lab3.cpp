#include "Geometric_progression.h"
#include "help_modul.h"

using namespace std;

int main()
{
    vector<Geometric_progression> progressions;
    int leng, num;

    cout << "Enter how many progressions you want to specify: ";
    cin >> leng;

    progressions = input_geo_progressions(leng);
    num = find_max(progressions);

    for (int i = 0; i < leng; i++)
    {
        progressions[i].output_str(i + 1);
    }
    cout << endl << endl << "Geometric progression with largest last term: " << num + 1 << endl;
}