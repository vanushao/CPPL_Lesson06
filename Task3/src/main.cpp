#include <iostream>
#include <initializer_list>
#include <stdexcept>

using namespace std::literals;
template <class T>
class simple_vector{
public:
    simple_vector(){}

    simple_vector(int size){
        sv_size_ = size;
        sv_capacity_ = (sv_size_ > 4)?2 * sv_size_ : sv_size_;
        arr_ = new T[sv_capacity_];
    }

    simple_vector(std::initializer_list<T> lst){
        if (lst.size() != 0){
            sv_size_ = lst.size();
            arr_ = new T[lst.size()];
            sv_capacity_ = (sv_size_ > 4)?2 * sv_size_ : sv_size_;
            int i = 0;
            for (auto it = lst.begin(); it < lst.end(); ++it){
                arr_[i] = *it;
                ++i;
            }
        }
    }

    ~simple_vector(){
        delete []arr_;
        arr_=nullptr;
        std::cout << "deleted"s << std::endl;
    }

    T& at(int index){
        if (index >= sv_size_){
            throw(std::out_of_range("Error: index >= size"s));
        }
        return arr_[index];
    }

    void push_back(T elem){
        if (sv_size_ < sv_capacity_){
            arr_[sv_size_] = elem;
            ++sv_size_;
        }else{
            resize_array();
            arr_[sv_size_-1] = elem;

        }
    }

    size_t size(){
        return sv_size_;
    }

    size_t capacity(){
        return sv_capacity_;
    }


private:
    size_t sv_capacity_ = 0;
    size_t sv_size_ = 0;
    T *arr_ = nullptr;

    void resize_array(){
        size_t tmp_size = sv_size_ + 1;
        size_t tmp_capacity = (tmp_size > 4)?2 * tmp_size : tmp_size;
        T *tmp_arr_ = new T[tmp_capacity];
        for (int i = 0; i < sv_size_; ++i) tmp_arr_[i] = arr_[i];
        delete [] arr_;
        sv_size_ = tmp_size;
        sv_capacity_ = tmp_capacity;
        arr_ = new T[sv_capacity_];
        for (int i = 0; i < sv_size_; ++i) arr_[i] = tmp_arr_[i];
        delete [] tmp_arr_;
    }
};


int main(){

    {
        simple_vector<int> test;

        std::cout << test.size() << " " << test.capacity() << std::endl;
        test.push_back(1);
        std::cout << test.size() << " " << test.capacity() << std::endl;
        test.push_back(2);
        std::cout << test.size() << " " << test.capacity() << std::endl;
        test.push_back(3);
        std::cout << test.size() << " " << test.capacity() << std::endl;
        test.push_back(4);
        std::cout << test.size() << " " << test.capacity() << std::endl;
        test.push_back(5);
        std::cout << test.size() << " " << test.capacity() << std::endl;
        test.push_back(6);
        std::cout << test.size() << " " << test.capacity() << std::endl;
        test.push_back(7);
        std::cout << test.size() << " " << test.capacity() << std::endl;
        test.push_back(8);
        std::cout << test.size() << " " << test.capacity() << std::endl;

        std::cout << test.at(0) << " " << test.at(1) << " " << test.at(2) << " " << test.at(3) << " " << test.at(4) << " " << test.at(5) << " " << test.at(6) << std::endl;

        try{
            test.at(8);
        }catch(const std::exception& err){
            std::cout << err.what() << std::endl;
        }
    }
    {
        simple_vector<int> test(7);
        std::cout << test.size() << " " << test.capacity() << std::endl;
        test.push_back(1);
        std::cout << test.size() << " " << test.capacity() << std::endl;
        test.push_back(2);
        std::cout << test.size() << " " << test.capacity() << std::endl;
        test.push_back(3);
        std::cout << test.size() << " " << test.capacity() << std::endl;
        test.push_back(4);
        std::cout << test.size() << " " << test.capacity() << std::endl;
        test.push_back(5);
        std::cout << test.size() << " " << test.capacity() << std::endl;
        test.push_back(6);
        std::cout << test.size() << " " << test.capacity() << std::endl;
        test.push_back(7);
        std::cout << test.size() << " " << test.capacity() << std::endl;
        test.push_back(8);
        std::cout << test.size() << " " << test.capacity() << std::endl;

        std::cout << test.at(0) << " " << test.at(1) << " " << test.at(2) << " " << test.at(3) << " " << test.at(4) << " " << test.at(5) << " " << test.at(6) << std::endl;

        try{
            test.at(8);
        }catch(const std::exception& err){
            std::cout << err.what() << std::endl;
        }
    }

    {
        simple_vector<int> test{1,2,3,4,5,6,7,8};
        std::cout << test.size() << " " << test.capacity() << std::endl;

        std::cout << test.at(0) << " " << test.at(1) << " " << test.at(2) << " " << test.at(3) << " " << test.at(4) << " " << test.at(5) << " " << test.at(6) << std::endl;

        try{
            test.at(8);
        }catch(const std::exception& err){
            std::cout << err.what() << std::endl;
        }
    }

    return 0;
}