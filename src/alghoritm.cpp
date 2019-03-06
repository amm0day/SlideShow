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

void    Images::setRelations(){
    List<Img*>  list = this->H;
    int         s;
    Rel*        tmp;

    for (int i = 0; i < list.getSize(); i++) {
        for (int j = i; j < list.getSize(); j++) {
            s = 0;
            for (int x = 0; x < list[i]->tag_size; x++){
                for (int y = 0; y < list[i]->tag_size; y++){
                    if (list[i]->tags[x] == list[j]->tags[y])
                        s++;
                }
            }
            s = min(list[i]->tag_size - s, s, list[j]->tag_size - s);
            if (s){
                tmp = new Rel();
                tmp->rel_id = j;
                tmp->weight = s;
                list[i]->relations.pushBack(tmp);
                tmp = new Rel();
                tmp->rel_id = i;
                tmp->weight = s;
                list[j]->relations.pushBack(tmp);
            }
        }
    }


    for (int i = 0; i < list.getSize(); i++) {
        cout  << "Nodul: " << i << endl ;
        for (int j = 0; j < list[i]->relations.getSize(); j++) {
            cout << list[i]->relations[j]->rel_id << " -> " << list[i]->relations[j]->weight << endl;
        }
        cout << endl;
    }
}
