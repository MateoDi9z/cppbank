//?   # PROTOTYPES #

//?   <- Menu ->
/*
*   Menu de Usuarios.
*   @return void
*   @since v1.0
*/
void UserMenu(void);

/*
*   Menu de Transacciones.
*   @return void
*   @since v1.0
*/
void TxMenu(void);
//?   <- Menu ->

//?   <- User ->
/*
* 	Agregar usuario.
*   @return void
*   @since v1.1
*/
void newUser(void);

/*
* 	Muestra los usuarios.
*   @return void
*   @since v1.1
*/
void showUsers(void);

/*
*   Borra usuario seleccionado
*   @return void
*   @since v1.2
*/
void deleteUser(void)
//?   <- User ->

//?   <- Database ->
/*
*   Leer linea por linea base de datos
*   @return bool -> 1 error | 0 ok!
*   @since v1.2
*/
bool ChecksDB(void);

/*
*   Escribir parametro 'line' en archivo 'db'
*   @param db Path relativo de base de datosborrar
*   @param line Linea a escribir en el archivo
*   @return void
*   @since v1.2
*/
void WriteDB(string db, string line);

/*
*   Leer linea por linea base de datos
*   @param db Path relativo de base de datos
*   @return void
*   @since v1.2
*/
void ReadDB(string db);

/*
*   Borrar linea de archivo
*   @param db Path relativo de base de datos
*   @param eraseID Id de usuario a borrar
*   @return void
*   @since v1.2
*/
void DeleteLineDB(string db, string eraseID);
//?   <- Database ->

//?   <- Misc ->
/*
*   Salteo de menu principal con argumento de programa.
*   @param arg string ("User" or "Tx")
*   @return void
*   @since v1.1
*/
void fastMenu(string arg);
//?   <- Misc ->