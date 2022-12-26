// *********************************************************************
// **
// ** Function ply::read (declaration)
// **
// ** Carlos Ureña - 2012- 2018
// **
// ** Lector de archivos PLY: usa std::vector y Tupla3f, Tupla3i
// ** Lee caras y v (ply::read), o bien solo vértices (ply::read_v)
// **
// ** This program is free software: you can redistribute it and/or modify
// ** it under the terms of the GNU General Public License as published by
// ** the Free Software Foundation, either version 3 of the License, or
// ** (at your option) any later version.
// **
// ** This program is distributed in the hope that it will be useful,
// ** but WITHOUT ANY WARRANTY; without even the implied warranty of
// ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// ** GNU General Public License for more details.
// **
// ** You should have received a copy of the GNU General Public License
// ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
// **
// *********************************************************************

#ifndef PLY_READER_H_INCLUDED
#define PLY_READER_H_INCLUDED

#include <vector>
#include <string>
#include "tuplasg.h"

namespace ply
{

// **********************************************************************
// **
// ** ply::read
// **
// **  lee un archivo ply y lo carga en 'v' y 'caras'
// **
// **   - 'nombre_archivo' nombre del archivo (se le añade .ply si no
// **     acaba en .ply)
// **   - si hay un error, aborta
// **   - elimina cualquier contenido previo en los
// **     vectores 'v' y 'caras'
// **   - lee el archivo .ply y lo carga en 'v' y 'caras'
// **   - solo admite plys con triángulos,
// **   - no lee colores, coordenadas de textura, ni normales.
// **
// *********************************************************************

void read
(
   const std::string &     nombre_archivo_pse, // entrada: nombre de archivo
   std::vector<Tupla3f> &  v,           // salida:  vector de coords. de vert.
   std::vector<Tupla3i> &  caras               // salida:  vector de triángulos (índices)
);


// **********************************************************************
// **
// ** ply::read_v
// **
// **  lee los vértices de un archivo ply y los carga en 'v'
// **
// **   - 'nombre_archivo' nombre del archivo (se le añade .ply si no
// **     acaba en .ply)
// **   - si hay un error, aborta
// **   - elimina cualquier contenido previo en el
// **     vector 'v'
// **   - lee el archivo .ply y carga los vértices en 'v'
// **   - no lee colores, caras, coordenadas de textura, ni normales.
// **   - se ignora la información de caras
// **
// *********************************************************************

void read_v
(
   const std::string &    nombre_archivo_pse, // entrada: nombre de archivo
   std::vector<Tupla3f> & v            // salida:  vector de coords. de vert.
);

} ; // fin namespace ply

#endif // _PLY_H
