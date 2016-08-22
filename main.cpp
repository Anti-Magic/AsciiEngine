#include "Engine.h"

// sample
#include "BadApple.h"
#include "Graph.h"
#include "Snake.h"

int main(int argc, const char * argv[]) {
    Engine::instance()->start(new BadApple());
    
    printf("press enter to exit...\n");
    getchar();
    
    return 0;
}
