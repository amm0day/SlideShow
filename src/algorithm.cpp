#include "../include/SlideShow.h"

int     min(int n, int n1, int n2) {
    if (n <= n1 && n <= n2) {
        return (n);
    } else if (n1 <= n && n1 <= n2) {
        return (n1);
    } else {
        return (n2);
    }
}

int    Images::getRelWeight(Img* r, Img* h){
    int     weight = 0;

    for(int i = 0; i < h->tag_size; i++) {
        for(int j = 0; j < r->tag_size; j++) {
            if (h->tags[i] == r->tags[j]){
                weight++;
            }
        }
    }
    weight = min(h->tag_size - weight, weight, r->tag_size - weight);
    return weight;
}


void    Images::solveIt(){
    Img*        current;
    Img*        tmpP;
    int         pos;
    int         weight;
    int         tmp;
    int         sum = 0;
    int         i;
    this->R = this->H;
    this->H = this->H->pNext;
    this->R->pNext = nullptr;

    while(this->H){
        weight = 0;
        pos = 0;
        current = this->H;
        i = 0;
        while(current){
            tmp = getRelWeight(this->R, current);
            if (weight < tmp){
                weight = tmp;
                pos = i;
            }
            i++;
            current = current->pNext;
        }
        current = this->H;
        cout <<">";
        if (pos){
            while(--pos){
                current = current->pNext;
            }
            tmpP = current->pNext;
            current->pNext = current->pNext->pNext;
            tmpP->pNext = this->R;
            this->R = tmpP;
        } else {
            this->H = this->H->pNext;
            current->pNext = this->R;
            this->R = current;
        }
        sum += weight;
    }
    cout << "RESULATUL NOSTRU = "<< sum << endl;
    current = this->R;
    while(current){
        cout << current->index << endl;
        current = current->pNext;
    }
}