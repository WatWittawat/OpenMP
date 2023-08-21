#include <stdio.h>
#include <omp.h>

int main()
{
    int res = 0;
    int MaxThread = omp_get_max_threads();
    int parlSum[MaxThread];
    int numID;
    scanf("%d", &numID);
    int a[numID];
    for (int i = 0; i < numID; i++)
        scanf("%d", &a[i]);
    #pragma omp parallel
        {
            int tmp = 0, numThread = omp_get_num_threads(), nowThread = omp_get_thread_num();
            int chunk = numID / numThread; 
            int st = nowThread * chunk;
            int end = 0;
            if (nowThread == numThread - 1){
                end = numID;
            } else{
                end = st + chunk;
            }
            for (int i = st; i < end; i++)
                tmp += a[i];
            parlSum[nowThread] = tmp;
        }
    for (int i = 0; i < MaxThread; i++)
        res += parlSum[i];
    printf("%d", res / numID);
    printf("\n");
    return 0;
}
