#include "Resource.h"



void Something(){
    Resource* res = new Resource;

    delete res;

    return;
}




int main(){

    Something();

    return 0;
}