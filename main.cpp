#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <utility>
#include <numeric>

using namespace std;

typedef struct person
{
  string name;
  int age;
  int id;
  person(string name, int age, int id): name(name), age(age), id(id){}
  virtual ~person() = default;

  inline bool operator <(const person& a) const {
    return id < a.id;
  }

  inline bool operator >(const person& a) const {
    return id > a.id;
  }

  inline bool operator ==(const person& a) const noexcept{
    return this->name == a.name and 
           this->id == a.id and 
           this->age == a.age;
  }

  friend ostream& operator << (ostream& output,const person& a){
    output<< a.name<<" : "<<a.age<<" : "<<a.id<<std::endl;
    return output;
  }
} Person;

 
struct hash_fp{
  size_t operator()(const Person& t) const{
    return std::hash<string>()(t.name) ^ std::hash<int>()(t.id); 
  }
};

namespace std{
template<>
struct hash<Person>{
  size_t operator()(const Person& t) const{
    return std::hash<string>()(t.name) ^ std::hash<int>()(t.id); 
  }
};
}

template<class T>
struct plus2{
	inline void operator() (T& x) const {
		x = x + 2;
	}
};

int main()
{

  // Set test 
  set<Person> test;
  test.insert(Person({"a", 19, 0}));
  test.insert({"a", 19, 1});
  test.insert({"a", 19, 2});

  const auto& ite = test.find({"a", 19, 2});

	if(ite != test.end()){
    std::cout<<"Find it"<<std::endl;
  }else{
    std::cout<<"Can not find it"<<std::endl;
  }

  for(auto ite = test.begin(); ite != test.end(); ++ite){
    std::cout<<*ite<<std::endl;
  }

  // Map test
  std::map<Person, int, greater<Person>> map_test = {
    {{"a", 19, 1}, 3},
    {{"a", 19, 12}, 6},
    {{"a", 19, 6}, 9}
  };

  map_test.insert({{"a", 19, 1}, 3});
  map_test.insert({{"a", 19, 1}, 3}); 
  std::pair<Person, int> temp = std::make_pair(Person("a", 19, 1), 3);

  for(auto ite = map_test.begin(); ite != map_test.end(); ++ite){
    std::cout<< "Key is : "<<ite->first<<"; Value is : "<<ite->second<<std::endl;
  }

  //unodered map
  std::unordered_map<Person, int, hash_fp> unordered_map_test = {
    {{"a", 19, 1}, 3},
    {{"a", 19, 12}, 6}
  };
  std::unordered_map<Person, int> unordered_map_test2 = {
    {{"a", 19, 1}, 3},
    {{"a", 19, 12}, 6}
  };

  // Algorithm
  std::vector<int> vector_test = {1,2,3,4,5,5};
  for_each(vector_test.begin(), vector_test.end(), plus2<int>());
  for_each(vector_test.begin(), vector_test.end(), [](int& x, int v = 2 ){ x += v;});
  for_each(vector_test.begin(), vector_test.end(), [](int& x){ std::cout<<x; });
  std::reverse(vector_test.begin(), vector_test.end());
  std::cout<<"Max element : "<< *std::max_element(vector_test.begin(), vector_test.end())<<std::endl;
  std::unique(vector_test.begin(), vector_test.end());

  std::transform(vector_test.begin(), vector_test.end(), vector_test.begin(), [](int& x){ return x *= x;});
  std::remove_if(vector_test.begin(), vector_test.end(), [](int& x){ return x == 81; });
  int sum_res  = std::accumulate(vector_test.begin(), vector_test.end(), 0);
  int sum_res2 = std::accumulate(vector_test.begin(), vector_test.end(), 1, std::multiplies<int>());
  // Numeric
  int sum = std::accumulate(vector_test.begin(), vector_test.end(), 0);
  int inner_product = std::inner_product(vector_test.begin(), vector_test.end(), 
                                          vector_test.begin(), 0);
	return 0;
}
