#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
private:
    vector<int> m_vec;//用于数据的随机访问
    unordered_map<int,int> m_map;//用于判断数据是否存在
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if( m_map.find(val) != m_map.end() )  return false;//元素已经存在      
        m_vec.push_back(val);//插入元素
        m_map[val] = m_vec.size()-1;//保存元素下标
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if( m_map.find(val) == m_map.end() )  return false;//元素不存在

        int index = m_map[val];//获取元素位置
        int temp = m_vec.back();//末尾元素值
        m_vec[index] = temp;//把末尾元素值保存到当前元素的位置
        m_map[temp] = index;//更新末尾元素值的下标
        m_vec.pop_back();//删除末尾元素
        m_map.erase(val);//删除元素位置
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if( m_vec.size() == 0 ) return -1;
        int index = rand() % m_vec.size();//生成随机位置
        return m_vec[index];
    }
};