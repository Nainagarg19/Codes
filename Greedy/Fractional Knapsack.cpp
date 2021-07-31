//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool comp(Item a, Item b)
    {
        double ar= (double)a.value/ (double)a.weight;
        double br=(double)b.value/ (double)b.weight;
        return ar>br;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, comp);
        double sum=0.0,c=0;
        int i=0;
        
        for(i=0;i<n;i++)
        {
            if(c+arr[i].weight<=W)
            {
                sum+=(double)arr[i].value;
                c+=(double)arr[i].weight;
            }
            else
            {
                sum+=(W-c)*((double)arr[i].value/(double)arr[i].weight);
                break;
            }
            
        }
        return sum;
    }
        
};
