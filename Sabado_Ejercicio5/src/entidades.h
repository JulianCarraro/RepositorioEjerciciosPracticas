/*
 * entidades.h
 *
 *  Created on: 7 may. 2022
 *      Author: carra
 */

#ifndef ENTIDADES_H_
#define ENTIDADES_H_

typedef struct {
    int idUser; // PK
    char nombre[125];
} User;

typedef struct {
    int idPosteo; // PK
    char comentario[256];
    int idUser; // FK
} Posteo;

typedef struct {
    int idHashtag;
    char descripcion[256];
} Hashtag;

typedef struct {
    int idHashtag;
    int idPosteo; // FK
} Relacion;

#endif /* ENTIDADES_H_ */
