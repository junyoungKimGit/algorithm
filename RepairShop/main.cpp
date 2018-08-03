//

#define MAXSIZE 11
#define MAXPEOPLE 1002

#pragma warning(disable:4996)

int numCheck;
int numRepair;
int numPeople;
int numA, numB;

int checkTime[MAXSIZE];
int curCheck[MAXSIZE][2];
int repairTime[MAXSIZE];
int curRepair[MAXSIZE][2];

int finalResult[MAXPEOPLE][2];

int arrivalTime[MAXPEOPLE];
int tPtr;

int waitingPeople[MAXPEOPLE][3];
int sPtr;
int ePtr;

void insertStack(int id, int time, int deskId) {
	waitingPeople[ePtr][0] = id;
	waitingPeople[ePtr][1] = time;
	waitingPeople[ePtr][2] = deskId;
	ePtr++;
}

void popStack(int *retId) {
	int ret = sPtr;
	int id = waitingPeople[ret][0];
	int cTime = waitingPeople[ret][1];
	int deskId = waitingPeople[ret][2];
	int i = ret + 1;
	while (waitingPeople[i][1] == cTime) {
		if (waitingPeople[i][2] < deskId) {
			ret = i;
			id = waitingPeople[i][0];
		}
		i++;
	}
	if (ret != sPtr) {
		int tmpId = waitingPeople[sPtr][0];
		int tmpTime = waitingPeople[sPtr][1];
		waitingPeople[sPtr][0] = waitingPeople[ret][0];
		waitingPeople[sPtr][1] = waitingPeople[ret][1];
		waitingPeople[ret][0] = tmpId;
		waitingPeople[ret][1] = tmpTime;
	}
	*retId = waitingPeople[sPtr][0];
	waitingPeople[sPtr][0] = -1;
	sPtr++;
	return;
}

void init() {
	sPtr = 0;
	ePtr = 0;
	tPtr = 1;
	for (int i = 0; i < MAXSIZE; i++) {
		curCheck[i][0] = -1;
		curCheck[i][1] = -1;
		curRepair[i][0] = -1;
		curRepair[i][1] = -1;
	}
	for (int i = 1; i <= numPeople; i++) {
		waitingPeople[i][0] = -1;
		waitingPeople[i][1] = -1;
	}
}



int finishedTime() {
	int clock = 0;
	int finished = 0;
	int ret = 0;
	while (finished < numPeople) {
		for (int i = 1; i <= numCheck; i++) {
			if (curCheck[i][0] != -1) {
				curCheck[i][1]--;
				if (curCheck[i][1] == 0) {
					finalResult[curCheck[i][0]][0] = i;
					insertStack(curCheck[i][0], clock, i);
					curCheck[i][0] = -1;
				}
			}
			if (curCheck[i][0] == -1 && arrivalTime[tPtr] <= clock && tPtr <= numPeople) {
				curCheck[i][0] = tPtr;
				curCheck[i][1] = checkTime[i];
				tPtr++;
			}
		}
		for (int i = 1; i <= numRepair; i++) {
			if (curRepair[i][0] != -1) {
				curRepair[i][1]--;
				if (curRepair[i][1] == 0) {
					finished++;
					finalResult[curRepair[i][0]][1] = i;
					if (finalResult[curRepair[i][0]][0] == numA && i == numB) {
						ret += curRepair[i][0];
					}
					curRepair[i][0] = -1;
				}
			}
			if (curRepair[i][0] == -1) {
				int id;
				if (ePtr - sPtr > 0) {
					popStack(&id);
					curRepair[i][0] = id;
					curRepair[i][1] = repairTime[i];
				}
			}
		}
		clock++;
	}



	if (ret == 0) {
		return -1;
	}
	return ret;
}

int main(void)
{
	int testCase;
	//freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &testCase);
	for (int m = 1; m <= testCase; m++)
	{
		scanf("%d %d %d %d %d", &numCheck, &numRepair, &numPeople, &numA, &numB);
		init();
		for (int i = 1; i <= numCheck; i++) {
			scanf("%d", &checkTime[i]);
		}
		for (int i = 1; i <= numRepair; i++) {
			scanf("%d", &repairTime[i]);
		}
		for (int i = 1; i <= numPeople; i++) {
			scanf("%d", &arrivalTime[i]);
		}
		printf("#%d %d\n", m, finishedTime());
	}
	return 0;
}
