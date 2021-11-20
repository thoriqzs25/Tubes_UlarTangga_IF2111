#include "player.h"
#include "../../boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void createEmptyPlayerList (pUserName *pU) {
    (*pU).Neff = 0;
}

void createEmptyPlayerSkillsList (Skill *S) {
    ADDR_HEADSKILL(*S) = Nil;
}

address newSkillNode () {
    lsNode *P = (lsNode *)malloc(sizeof(lsNode));
    if (P != Nil) {
        NEXTSKILL(P) = Nil;
        strcpy(SKILLNAME(P), "kosong");
        return P;
    }
    else {
        return Nil;
    }
}

void preparationSkillList (Skill *pS1, Skill *pS2, Skill *pS3, Skill *pS4, int n) {
    for (int i = 1; i <= n ; i ++) {
        if (i == 1) {
            createEmptyPlayerSkillsList(pS1);
        }
        else if (i == 2) {
            createEmptyPlayerSkillsList(pS2);
        }
        else if (i == 3) {
            createEmptyPlayerSkillsList(pS3);
        }
        else if (i == 4) {
            createEmptyPlayerSkillsList(pS4);
        }
    }
}

int banyaknyaSkill (Skill pS1, Skill pS2, Skill pS3, Skill pS4, int idxP) {
    address P;
    int count = 0;
    if (idxP == 1) {
        P = ADDR_HEADSKILL(pS1);
    }
    else if (idxP == 2) {
        P = ADDR_HEADSKILL(pS2);
    }
    else if (idxP == 3) {
        P = ADDR_HEADSKILL(pS3);
    }
    else if (idxP == 4) {
        P = ADDR_HEADSKILL(pS4);
    }
    while (P != Nil) {
        count++;
        P = NEXTSKILL(P);
    }
    return count;
}

int returnIdxSkill (Skill pS1, Skill pS2, Skill pS3, Skill pS4, int idxP, char *skName) {
    address P;
    if (idxP == 1) {
        P = ADDR_HEADSKILL(pS1);
    }
    else if (idxP == 2) {
        P = ADDR_HEADSKILL(pS2);
    }
    else if (idxP == 3) {
        P = ADDR_HEADSKILL(pS3);
    }
    else if (idxP == 4) {
        P = ADDR_HEADSKILL(pS4);
    }

    char temp[30];
    int idxS = 1;
    strcpy(temp, skName);
    boolean found = FALSE;
    while ((P != Nil) && (!found)) {
        if (strcmp(SKILLNAME(P), temp) == 0) {
            found = TRUE;
        }
        else {
            idxS++;
            P = NEXTSKILL(P);
        }
    }
    if (found) {
        return idxS;
    }
    else {
        return IdxUndef;
    }
}

boolean isSkillExists (Skill pS1, Skill pS2, Skill pS3, Skill pS4, int idxP, char *skName) {
    address P;
    if (idxP == 1) {
        P = ADDR_HEADSKILL(pS1);
    }
    else if (idxP == 2) {
        P = ADDR_HEADSKILL(pS2);
    }
    else if (idxP == 3) {
        P = ADDR_HEADSKILL(pS3);
    }
    else if (idxP == 4) {
        P = ADDR_HEADSKILL(pS4);
    }

    char temp[30];
    strcpy(temp, skName);
    boolean found = FALSE;
    while ((P != Nil) && (!found)) {
        if (strcmp(SKILLNAME(P), temp) == 0) {
            found = TRUE;
        }
        else {
            P = NEXTSKILL(P);
        }
    }
    return found;
}

void deleteSkill (Skill *pS1, Skill *pS2, Skill *pS3, Skill *pS4, int idxP, int idxS) {
    address P;
    address Prec;
    if (idxP == 1) {
        P = ADDR_HEADSKILL(*pS1);
    }
    else if (idxP == 2) {
        P = ADDR_HEADSKILL(*pS2);
    }
    else if (idxP == 3) {
        P = ADDR_HEADSKILL(*pS3);
    }
    else if (idxP == 4) {
        P = ADDR_HEADSKILL(*pS4);
    }
    
    if (idxS != 1) {
        Prec = P;
        P = NEXTSKILL(P);
        int idx = 2;
        while ((idx != idxS) && (P != Nil)) {
            idx++;
            Prec = NEXTSKILL(Prec);
            P = NEXTSKILL(P);
        }
        NEXTSKILL(Prec) = NEXTSKILL(P);
        NEXTSKILL(P) = Nil;
        free(P);
    }
    else {
        if (idxP == 1) {
            ADDR_HEADSKILL(*pS1) = NEXTSKILL(P);
            NEXTSKILL(P) = Nil;
            free(P);
        }
        else if (idxP == 2) {
            ADDR_HEADSKILL(*pS2) = NEXTSKILL(P);
            NEXTSKILL(P) = Nil;
            free(P);
        }
        else if (idxP == 3) {
            ADDR_HEADSKILL(*pS3) = NEXTSKILL(P);
            NEXTSKILL(P) = Nil;
            free(P);
        }
        else if (idxP == 4) {
            ADDR_HEADSKILL(*pS4) = NEXTSKILL(P);
            NEXTSKILL(P) = Nil;
            free(P);
        }
    }
}

void summonPlayer (pUserName *pU, pIsTeleported *pT, pPosition *pP, pIsImune *pI, pIsCermin *pC, 
pIsSenterBesar *pSB, pIsSenterKecil *pSK, pIsMesinWaktu *pMW, 
pIsBalingBaling *pB, pIsPenukar *pPen, pIsTeknologiGagal *pTG, int n) {
    for (int i = 1 ; i <= n ; i++) {
        printf("coba masukin uname\n");
        scanf("%s", &((*pU).uname[i]));
        (*pT).isTele[i] = FALSE;
        (*pP).pos[i] = 1;
        (*pI).isImun[i] = FALSE;
        (*pC).isCermin[i] = FALSE;
        (*pSB).isSenterBesar[i] = FALSE;
        (*pSK).isSenterKecil[i] = FALSE;
        (*pMW).isMesin[i] = FALSE;
        (*pB).isBaling[i] = FALSE;
        (*pPen).isTukar[i] = FALSE;
        (*pTG).isTek[i] = FALSE;
    }
    (*pU).Neff = n;
}

int getIdxOfPlayer(pUserName pU, char *name) {
    int i = IdxMin;
    char temp[16];
    strcpy(temp, name);
    while ((strcmp(pU.uname[i], temp) != 0) && (i <= IdxMax)) {
        ++i;
    }
    if (i <= IdxMax) {
        return i;
    }
    else {
        return IdxUndef;
    }
}

boolean isEmptyList (Skill pS) {
    return ((ADDR_HEADSKILL(pS)) == Nil);
}

void insertVSkill (Skill *pS, char *skname) {
    if (isEmptyList(*pS)) {
        address P = newSkillNode();
        strcpy(SKILLNAME(P), skname);
        NEXTSKILL(P) = Nil;
        ADDR_HEADSKILL(*pS) = P;
    }
    else {
        address P = ADDR_HEADSKILL(*pS);
        int count = 1;
        while ((NEXTSKILL(P) != Nil) && (count <= 10)) {
            count++;
            P = NEXTSKILL(P);
        }
        if (count <= 10) {
            address X = newSkillNode();
            strcpy(SKILLNAME(X), skname);
            NEXTSKILL(X) = Nil;
            NEXTSKILL(P) = X;
        }
    }
}

boolean getTeleportedConditionOfPlayer(pIsTeleported pT, int idx) {
    if (idx != IdxUndef) {
        return (pT.isTele[idx]);
    }
}

boolean getImmunityConditionOfPlayer (pIsImune pI, int idx) {
    if (idx != IdxUndef) {
        return (pI.isImun[idx]);
    }
}

int getPositionOfPlayer (pPosition pP, int idx) {
    if (idx != IdxUndef) {
        return (pP.pos[idx]);
    }
}

boolean getCerminConditionOfPlayer (pIsCermin pC, int idx) {
    if (idx != IdxUndef) {
        return (pC.isCermin[idx]);
    }
}

boolean getSenterBesarConditionOfPlayer (pIsSenterBesar pSB, int idx) {
    if (idx != IdxUndef) {
        return (pSB.isSenterBesar[idx]);
    }
}

boolean getSenterKecilConditionOfPlayer (pIsSenterKecil pSK, int idx) {
    if (idx != IdxUndef) {
        return (pSK.isSenterKecil[idx]);
    }
}

boolean getMesinWaktuConditionOfPlayer (pIsMesinWaktu pMW, int idx) {
    if (idx != IdxUndef) {
        return (pMW.isMesin[idx]);
    }
}

boolean getBalingBalingConditionOfPlayer (pIsBalingBaling pB, int idx) {
    if (idx != IdxUndef) {
        return (pB.isBaling[idx]);
    }
}

boolean getPenukarConditionOfPlayer (pIsPenukar pPen, int idx) {
    if (idx != IdxUndef) {
        return (pPen.isTukar[idx]);
    }
}

boolean getTeknologiGagalConditionOfPlayer (pIsTeknologiGagal pTG, int idx) {
    if (idx != IdxUndef) {
        return (pTG.isTek[idx]);
    }
}