#include "Model.h"
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<stdlib.h>
#include "Color.h"
#include "Matrix.h"
#include<cmath>
using namespace std;


Model::Model(){
    vector<Triangle3D> triangles;
}


int Model::numTriangles(){
    return triangles.size();
}

Triangle3D Model::operator[](int i){
    return triangles[i];
}

void Model::transform(Matrix4 m){
    for(int i = 0; i < triangles.size(); i++){
        triangles[i].transform(m);
    }
}

void Model::readFromOBJFile(string filepath, Color pFillColor){
    vector<Vector4> points;
    points.push_back(Vector4(-1, -1, -1, -1));

    ifstream file(filepath);
    if(file.is_open()){
        string line;
        while(getline(file, line)){

            istringstream s(line);
            string word;
            string check = "#";
            vector<float> coordinate;
            while(getline(s, word, ' ')){

                if(word == "v"){
                    check = "v";
                }
                else if(word == "f"){
                    check ="f";
                }
                else if(word == "#"){
                    check = "#";
                }
                else{
                    float val = atof(word.c_str());
                    coordinate.push_back(val);
                }
            }

            if(check == "v"){
                float x = coordinate[0];
                float y = coordinate[1];
                float z = coordinate[2];
                float w = 1;
                Vector4 vertex(x, y, z, w);

                points.push_back(vertex);
            }
            else if(check == "f"){
                int i1 = static_cast<int>(coordinate[0]);
                int i2 = static_cast<int>(coordinate[1]);
                int i3 = static_cast<int>(coordinate[2]);

                Vector4 p1 = points[i1];
                Vector4 p2 = points[i2];
                Vector4 p3 = points[i3];

                Triangle3D t(p1, p2, p3, pFillColor, pFillColor, pFillColor);

                triangles.push_back(t);
            }
            else if(check == "#"){
                continue;
            }
            else{
                cout << "Something wrong, check again" << endl;
                cout << "check is: " << check << endl;
            }

            coordinate.clear();
        }

        file.close();
    }
}