#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r, n, i, j, k, p;
    printf("Enter the number of processes: \n");
    scanf("%d", &n);
    printf("Enter the number of types of each resource: \n");
    scanf("%d", &r);
    int ALL[n][r], MAX[n][r], AVAIL[r], NEED[n][r], completed[n], sequence[n], total[r];
    printf("Enter the total number of resources: \n\n");
    for (i = 0; i < r; i++)
        scanf("%d", &total[i]);
    for (i = 0; i < n; i++)
    {
        printf("Enter the allocation matrix for process P%d:\n", i + 1);
        for (j = 0; j < r; j++)
            scanf("%d", &ALL[i][j]);
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter the maximum resources for process P%d:\n", i + 1);
        for (j = 0; j < r; j++)
            scanf("%d", &MAX[i][j]);
    }
    for (i = 0; i < n; i++)
        completed[i] = 0;

    for (i = 0; i < n; i++)
        sequence[i] = 999;

    for (i = 0; i < n; i++)
    { //Calculation of Need matrix
        for (j = 0; j < r; j++)
            NEED[i][j] = MAX[i][j] - ALL[i][j];
    }
    for (i = 0; i < r; i++)
    {
        int tot = 0;
        for (j = 0; j < n; j++)
            tot = tot + ALL[j][i];

        AVAIL[i] = total[i] - tot;
    }
    printf("\nAvailable Matrix:\n");
    for (i = 0; i < r; i++)
        printf("%d\t", AVAIL[i]);
    printf("\n\n");

    for (i = 0; i < n; i = (i + 1) % n)
    {
        int flag = 0;
        for (k = 0; k < n; k++)
        {

            if (completed[k] == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            break;

        else
        {
            int l = 0;
            for (p = 0; p < r; p++)
            {
                if (NEED[i][p] > AVAIL[p])
                    l = 1;
            }

            if (l == 0 && (completed[i] == 0))
            {
                for (j = 0; j < n; j++)
                {
                    if (sequence[j] == 999)
                    {
                        sequence[j] = i;
                        break;
                    }
                }
                printf("Process P%d has completed\n", i + 1);
                completed[i] = 1;

                for (p = 0; p < r; p++)
                    AVAIL[p] = AVAIL[p] + ALL[i][p];

                printf("Updtaes available resources: ");
                for (p = 0; p < r; p++)
                    printf("%d ", AVAIL[p]);
                printf("\n");
            }

            else
                continue;
        }
    }

    printf("\nSafe Sequence:\n");
    for (i = 0; i < n; i++)
        printf("P%d\t", sequence[i] + 1);
}
