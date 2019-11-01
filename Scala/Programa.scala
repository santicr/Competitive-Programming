//Ver el capitulo 17
object Programa{
	def main(args: Array[String]): Unit = {
		println("Hola mundo, esto es Scala")
		//Ejemplos de funciones en Scala
		/* En Scala, los parametros se escriben
			de la siguiente forma: variable: Tipo.
			al final de escribir la función deberás
			escribir que devuelve con un : Tipo, luego
			escribes = {codigo}. */
		def suma(x: Int, y: Int): Int = {
			x + y
		}
		//Ejemplos de match en Scala, en c++ es conocido como switch.
		val x = 2
		x match {
			case 1 => println("El valor es uno")
			case 2 => println("El valor es dos")
			case 3 => println("El valor es tres")
			case 4 => println("El valor es cuatro")
			case 5 => println("El valor es cinco")
			case 6 => println("El valor es seis")
		}
		//Más ejemplos de match en Scala.
		/* Cuando ningún caso se cumple,
			este caso se puede llamar _. */
		val y = 10
		println(y match{
			case 1 => "Ahora el valor es de uno"
			case 2 => "Ahora el valor es de dos"
			case 3 => "Ahora el valor es de tres"
			case 4 => "Ahora el valor es de cuatro"
			case 5 => "Ahora el valor es de cinco"
			case 6 => "Ahora el valor es de seis"
			case 7 => "Ahora el valor es de siete"
			case 8 => "Ahora el valor es de ocho"
			case 9 => "Ahora el valor es de nueve"
			case 10 => "Ahora el valor es de diez"
			case _ => "Ningun caso se cumple"
		})
		//Ejemplo de ciclos con WHILE
		var precio = 0
		while(precio < 5){
			println(s"El valor de precio es -> $precio, x -> $x")
			precio += 1
		}
		//Ejemplo de arrays
		val arreglo = Array(1,2,3,4,5) //Tipo Int, lo identifica automaticamente
		val arreglo2 = Array[Int](1,2,3,4,5) //Solo tipo Int
		val arreglo3 = Array(1,2,3,4,"Cinco") //Tipo Any
		val lista = List("Hola", "Amigos", "Como", "Estan")
		val mapa = Map("Pos1" -> 1, "Pos2" -> 2, "Pos3" -> 3)
		arreglo.apply(2) //Devuelve el valor de la posicion 2
		arreglo(2) //Tiene la misma función de apply
		arreglo.indexOf(1)
		println("En la pos 2 esta -> " + arreglo(2))
		println("El tamaño de el arreglo1 es " + arreglo.length)
		println("El valor 4 esta en la pos -> " + arreglo.indexOf(4))
		println("------------------------- FIN --------------------------")
	}
}