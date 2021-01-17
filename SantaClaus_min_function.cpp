using namespace std;

template <typename T>
T Santa_claus_min_funtion(T x, T y)//functie de calculare a minimului, utilizand template, pe care o folosesc la 
                                    //calcularea celui mai scurt drum in clasa SantaClaus
{
    return (x < y) ? x : y;
}