#include <iostream>
#include <Stack.h>
#include <time.h>

using namespace std;

int main(){
    int start = clock();    
    Stack<int> stack;
    for(int i = 0; i < 10000000; i++){
        stack.push(i);
    }
    cout<<endl;
    std::cout<<"push time : "<<clock() - start<<endl;

    stack.print();

    int startPop = clock();
    for(int j = 0; j < 10000000; j++){
        if(!stack.isEmpty()){
            int el = stack.pop();
            //cout<<el<<", ";
        }
    }
    cout<<endl;
    std::cout<<"pop time : "<<clock() - startPop<<endl;

    stack.print();
    return 0;
}


