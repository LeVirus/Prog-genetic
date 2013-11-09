#ifndef OPR
#define OPR

#include <vector>

class OpReproduction{
	private:
		std::vector<unsigned short> vectMemo;
	public:
		OpReproduction(std::vector<unsigned short> vect);
		void newGen();
		~OpReproduction();
};

#endif
