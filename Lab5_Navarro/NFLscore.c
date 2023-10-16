#include <stdio.h>

int main()
{
    int score;
    
    printf("Enter 0 or 1 to STOP\n");
    
    while(1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        
        if (score <= 1) {
            break;
        }
        
        int td, fg, safety, td_fg, td2;
        
        printf("Possible combinations of scoring plays:\n");
        
        for (safety = 0; safety * 2 <= score; safety++) {
            for (fg = 0; fg * 3 <= score; fg++) {
                for (td = 0; td * 6 <= score; td++) {
                    for (td_fg = 0; td_fg * 7 <= score; td_fg++) {
                        for (td2 = 0; td2 * 8 <= score; td2++) {
                            int total = (td * 6) + (fg * 3) + (safety * 2) + (td_fg * 7) + (td2 * 8);
                            if (total == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, td_fg, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }
    }
    
    printf("Program ended...");

    return 0;
}
