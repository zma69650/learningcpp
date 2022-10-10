#include "iostream"
#include "vector"

using namespace std;

// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

// 如果数组中不存在目标值 target，返回 [-1, -1]。

// 进阶：你可以设计并实现时间复杂度为 $O(\log n)$ 的算法解决此问题吗？


// 示例 1：
// 输入：nums = [5,7,7,8,8,10], target = 8
// 输出：[3,4]

// 示例 2：
// 输入：nums = [5,7,7,8,8,10], target = 6
// 输出：[-1,-1]




template <class T>
class FindFirstandEndInArray
{
private:
    /* data */
public:

    FindFirstandEndInArray();
    

    ~FindFirstandEndInArray();

    std::pair<int,int> getResults(T target,vector<T> array){
        int left = 0;
        int right = array.size() - 1;
        int middle = left + (right - left)/2;
        int pair_left = middle;
        int pair_right = middle;
        while (left<=right)
        {
            /* code */
            int middle = left + (right-left)/2;
            if(target > array[middle]){  //target value in right 
                left = middle + 1;
            }
            else if(target < array[middle]){
                right = middle - 1;
                pair_right = right;
            }  //target value in left
            else{
                left = middle + 1;
            }
        }
        return make_pair(-1,(int)right);
    }




};


template <class T>
FindFirstandEndInArray<T>::FindFirstandEndInArray(/* args */)
{
}


template <class T>
FindFirstandEndInArray<T>::~FindFirstandEndInArray()
{
}

int main()
{
    vector<int> array;
    array.resize(10,4);
    array[0]=1;
    array[1]=2;
    array[8]=5;
    array[9]=6;
    FindFirstandEndInArray<int> fp;
    std::pair<int,int> result = fp.getResults(4,array);
    cout<<"right: "<<result.second<<endl;
    
    return 0;
}
