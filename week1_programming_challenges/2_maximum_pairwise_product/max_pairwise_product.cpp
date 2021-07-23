#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}
long long MaxPairwiseProductFast(const vector<int>& numbers)
{
    int n = numbers.size();
    long long max = -1;
    long long max2 = -1;
    long long maxProduct;
    for(int i=0;i<n;i++){
        if((max==-1)||(numbers[i]>numbers[max])){
            max = i;
        }
    }
    for(int j=0;j<n;j++){
        if((j!=max)&&((max2==-1)||(numbers[j]>numbers[max2]))){
            max2 = j;
        }
    }
    maxProduct = (long long)numbers[max]*(long long)numbers[max2];
    return maxProduct;

}

int main() {
    int n;
    long long x;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    x = MaxPairwiseProductFast(numbers);
    cout <<x<<"\n";
    return 0;
}
