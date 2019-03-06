#include "../include/SlideShow.h"

int     min(int n, int n1, int n2) {
    if (n < n1 && n < n2) {
        return (n);
    } else if (n1 < n && n1 < n2) {
        return (n1);
    } else {
        return (n2);
    }
}

int    Images::getRelWeight(int r, int h){
    int     weight = 0;

    for(int i = 0; i < this->H[h]->tag_size; i++) {
        for(int j = 0; j < this->R[r]->tag_size; j++) {
            if (H[h]->tags[i] == R[r]->tags[j]){
                weight++;
            }
        }
    }
    weight = min(this->H[h]->tag_size - weight, weight, this->R[r]->tag_size - weight);
    return weight;
}


void    Images::solveIt(){
    int         pos;
    int         weight;
    int         tmp;
    int         sum = 0;
    this->R.pushFront(this->H[0]);
    this->H.delFront();

    for (int i = 0; i < this->R.getSize(); i++){
        weight = 0;
        pos = 0;
        for(int j = 0; j < this->H.getSize(); j++) {
            tmp = getRelWeight(0, j);
            if (weight < tmp){
                weight = tmp;
                pos = j;
            }
        }
        if(this->H.getSize()){
            this->R.pushFront(this->H[pos]);
            this->H.delIndex(pos);
            sum += weight;
        }
    }
    
    cout << R.getSize() << endl;
    // for(int i = 0; i < this->R.getSize(); i++){
    //     cout << this->R[i]->index;
    //     for(int tag = 0; tag < this->R[i]->tag_size; tag++)
    //     {
    //         cout << ' ' << this->R[i]->tags[tag];
    //     }
    //     cout << endl;
    // }
    cout << "RESULATUL NOSTRU = "<< sum << endl;
}