#include "include/SlideShow.h"

int main(int argc, char* argv[]){

    Images images = Images(argv[1]);

    images.solveIt();
    return (0);
}