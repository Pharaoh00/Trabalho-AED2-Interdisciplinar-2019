//
// Created by HamonRa on 17/11/2019.
//

#ifndef V6_TOOLS_H
#define V6_TOOLS_H

bool checkString(char *item) {
    // Retorna true se o array passado é uma string
    // Retorna false e o array passado contem characteres indesejados
    int len = strlen(item);
    int index = 0;
    bool flag = true;
    while (index < len) {
        // == 32 (numero ascii para espaço)
        // Caso queira mais caracteres, adicionar na checagem.
        if ((item[index] >= 'a' && item[index] <= 'z') ||
            (item[index] >= 'A' && item[index] <= 'Z') ||
            item[index] == 32) {
            flag = true;
            index++;
        } else {
            flag = false;
            break;
        }
    }
    return flag;
}

bool checkEndereco(char *item) {
    // Retorna true se o array passado é uma string
    // Retorna false e o array passado contem characteres indesejados
    int len = strlen(item);
    int index = 0;
    bool flag = true;
    while (index < len) {
        // == 32 (numero ascii para espaço)
        // == 45 (numero ascii para -     )
        // Caso queira mais caracteres, adicionar na checagem.
        if ((item[index] >= 'a' && item[index] <= 'z') ||
            (item[index] >= 'A' && item[index] <= 'Z') ||
            item[index] == 32 || item[index] == 45 || (item[index] >= 0 && item[index] <= INT_MAX)) {
            flag = true;
            index++;
        } else {
            flag = false;
            break;
        }
    }
    return flag;
}

bool checkLongLongInt(long long int item) {
    // LONG_LONG_MAX é o maior valor long long int
    // Maior que zero, porque os valores do sentinela são 0 ou x0 ou NULL.
    if (item > 0 && item <= LONG_LONG_MAX) {
        return true;
    } else {
        return false;
    }
}

bool checkInt(int numero) {
    if(numero > 0 && numero < INT_MAX) {
        return true;
    }
    else {
        return false;
    }
}

// função encontrar no post da stackoverflow:
// https://stackoverflow.com/questions/5289613/generate-random-float-between-two-floats
float randomFloat(float min, float max)
{
    // this  function assumes max > min, you may want
    // more robust error checking for a non-debug build
    //assert(max > min);
    if(max > min) {
        float random = ((float) rand()) / (float) RAND_MAX;

        // generate (in your case) a float between 0 and (4.5-.78)
        // then add .78, giving you a float between .78 and 4.5
        float range = max - min;
        return (random * range) + min;
    }
    else {
        float aux = max;
        max = min;
        min = aux;

        float random = ((float) rand()) / (float) RAND_MAX;

        // generate (in your case) a float between 0 and (4.5-.78)
        // then add .78, giving you a float between .78 and 4.5
        float range = max - min;
        return (random * range) + min;
    }
}

// função encontrar no post da stackoverflow:
// https://stackoverflow.com/questions/2509679/how-to-generate-a-random-integer-number-from-within-a-range
int randomInt(int max, int min)
{
    int range, result, cutoff;

    if (min >= max)
        return min; // only one outcome possible, or invalid parameters
    range = max-min+1;
    cutoff = (RAND_MAX / range) * range;

    // Rejection method, to be statistically unbiased.
    do {
        result = rand();
    } while (result >= cutoff);

    return result % range + min;
}

#endif //V6_TOOLS_H
