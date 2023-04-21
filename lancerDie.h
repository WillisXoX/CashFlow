#ifndef LANCERDIE_H_INCLUDED
#define LANCERDIE_H_INCLUDED

int lancerDie()
{

    int const dieMax=6, dieMin=1;

    srand((unsigned) time(NULL));
    int die = dieMin + (rand()% dieMax);

    return die;
}

#endif
