all: sequential parallel

sequential:
    g++ -std=c++11 -fopenmp sequential_main.cpp Point.h Cluster.h -o sequential_main

parallel:
    g++ -std=c++11 -fopenmp parallel_main.cpp Point.h Cluster.h -o parallel_main

clean:
    rm -f sequential_main parallel_main