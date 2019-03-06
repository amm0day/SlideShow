#include "../include/SlideShow.h"

void Images::readFile(string fpath){
    fstream     file(fpath);
    char        c;
    if(file.is_open()){
        file >> total_img;
        for(int i = 0; i < total_img; i++){
            Img* img = new Img;
            
            img->index = i;
            file >> c;
            file >> img->tag_size;
            img->tags = new string[img->tag_size];
            // Reading tags
            for (int j = 0; j < img->tag_size; j++) {
                file >> img->tags[j];
            // Insert images in List
            }
            if (c == 'H')
                this->H.pushBack(img);
            else if (c == 'V')
                this->V.pushBack(img);
        }
    }
}

// void Images::initRelations(){
//         H[i]->relations = new List<Rel*>;
//         V[i]->relations = new List<Rel*>;
// }