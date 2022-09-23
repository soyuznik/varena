#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Bee {
public:
	int i, j;
	Bee(int m_i, int m_j) { i = m_i; j = m_j; };
	bool is_inside(int size) {// ok
		return ((i <= size && i >= 0) && (j <= size && j >= 0));
	}
	void move(int dir) { // ok
		if (dir == 0) {
			i = i - 1;
		}
		if (dir == 1) {
			j = j + 1;
		}
		if (dir == 2) {
			i = i + 1;
		}
		if (dir == 3) {
			j = j - 1;
		}
	}
};
int main()
{
	int n_param;
	std::vector<int> misc;
	std::vector<Bee*> hive;
	int grame = 0;
	{
		ifstream fileR("./albine.in");
		{
			string text;
			{
				int it_param;
				std::getline(fileR, text);
				{
					stringstream s(text);
					s >> n_param >> it_param;
					if (n_param >= 10000) goto END;
					if (it_param >= 1000000) goto END;
				}
				std::getline(fileR, text);
				{
					stringstream s(text);
					for (int i = 0; i < it_param; i++) {
						string dat;
						s >> dat;
						misc.push_back(stoi(dat));
					}
				}
			}
		}
		fileR.close();
		for (int i = 0; i < n_param; i++) {
			for (int j = 0; j < n_param; j++) {
				Bee* bee = new Bee(i, j);
				hive.push_back(bee);
			}
		}
	}
	for (int i = 0; i < (int)misc.size(); i++) {
		for (Bee* b : hive) {
			b->move(misc[i]);
			if (!(b->is_inside(n_param - 1))) {
				grame++;
			}
		}
	}
END:
	ofstream fileW("./albine.out");
	fileW << grame;
	fileW.close();
}