
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct team {
  int id;
  int seed;
  char name[50];
} Team;

int playGame(Team,Team);
void readTeams(Team[64], char *fname);

int main(int argc, char *argv[]) {
  int i, winner, round = 1;
  int teamsLeft = 64;
  Team teams[64];
  readTeams(teams, argv[1]);

  srand(time(NULL));

  while( teamsLeft > 1 ) {
    printf("---   ROUND %d   ---\n", round++);
    for( i = 0; i < teamsLeft; i += 2 ) {
      if( teams[i].seed <= teams[i+1].seed ) {
        winner = playGame(teams[i],teams[i+1]);
      } else {
        winner = playGame(teams[i+1],teams[i]);
      }

      if( winner == teams[i].id ) {
        printf("%s\n", teams[i].name);
        if( i != 0 ) {
          memcpy(&teams[i/2], &teams[i], sizeof(Team));
        }
      } else {
        memcpy(&teams[i/2], &teams[i+1], sizeof(Team));
        printf("%s\n", teams[i+1].name);
      }
    }
    teamsLeft /= 2;
  }
}


int playGame(Team better, Team worse) {
  if( better.seed <= 2 && worse.seed >= 15) {
    return better.id;
  }
  double ratio = (double)worse.seed / (double)better.seed;
  int betterTeamScore = 101 - (int)(100.0 / (1 + ratio));
  int roll = rand() % 100 + 1;

  if( roll <= betterTeamScore ) {
    return better.id;
  }
  return worse.id;
}

void readTeams(Team teams[], char *fname) {
  FILE* ifile = fopen(fname, "r");
  int i;
  for( i = 0; i < 64; i++ ) {
    fscanf(ifile, "%d %d %s", &teams[i].id, &teams[i].seed, teams[i].name);
  }
  fclose(ifile);
}
