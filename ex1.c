#include <stdio.h>

int my_atoi(const char *str) {
    int result = 0;
    int i = 0;
    while (str[i] >= '0' && str[i] <= '9') { 
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

int main() {
    FILE *file = fopen("in.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    char line[100]; 
    int sum = 0;
    
    while (fgets(line, sizeof(line), file)) {
        sum += my_atoi(line);
    }
    
    fclose(file);
    
    printf("Sum: %d\n", sum);
    return 0;
}
