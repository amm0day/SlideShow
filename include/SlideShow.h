#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;



class Images {
public:
	class Img {
	public:
		Img*		pNext;

		int			index;
		int			tag_size;
		string		*tags;
		Img(Img* pNext = nullptr){this->pNext = pNext;}
	};

	int		total_img;
	Images(string fpath){
		readFile(fpath);
		// initRelations();
	}
	void	setRelations();
	void	solveIt();


	Img*	H = nullptr;
	Img*	V = nullptr;
    Img*	R = nullptr;

	void	readFile(string fpath);
	void	initRelations();
	int		getRelWeight(Img* r, Img* h);

};