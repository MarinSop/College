#include "Vrabac.h"
#include "Tarantula.h"
#include "Zohar.h"
#include "Brojac.h"

int main()
{
	Vrabac vrabac("vrabac",2);
	Tarantula tarantula("tarantula", 8);
	Zohar zohar("zohar", 6);
	Brojac br({ vrabac,tarantula,zohar });

	return 0;
}