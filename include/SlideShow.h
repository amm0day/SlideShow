#include "List.h"


class Images {
private:
	void	readFile(string fpath);
	void	initRelations();
	int		getRelWeight(int r, int h);


public:
	int		total_img;
	Images(string fpath){
		readFile(fpath);
		// initRelations();
	}
	void	setRelations();
	void	solveIt();

	class Rel{
	public:
		int			weight;
		int			rel_id;
	};

	class Img {
	public:
		int			index;
		int			tag_size;
		List<Rel*>	relations;
		string		*tags;
	};

	List<Img*>	H;
	List<Img*>	V;
    List<Img*>  R;
};