#include <stdio.h>
#include <string.h>

char buffer[1000000001];

int main(){
    int n, m, i, res, j;
    
        scanf("%d %d", &n, &m);
        
        memset(buffer, 0, sizeof(buffer));
        res = 0;
        for(i=0;i<n+m;i++){
            scanf("%d", &j);
            if(buffer[j]) res++;
            else{
                buffer[j] = 1;
            }
        }
        printf("%d\n", res);
    
    return 0;
}