object funciones{
	def main(args: Array[String]) = {
		def punto1(x: Int, y: Int): Double = {
			x * y
		}
		def punto2(x: Int): Double = {
			x * (9/5) + 32
		}
		val x = 2
		val y = 10
		val este = punto2(x)
		val otro = punto1(x, y)
		println(s"Funciono -> $este -> $otro")
		var arreglo = new Array[Int](10)
		var iterador = 0
		var valor = 0
		while(valor < 10){
			arreglo(valor) = 2 * valor
			valor = valor + 1
		}
		while(iterador < arreglo.length){
			println(s"Arreglo pos $iterador -> " + arreglo(iterador))
			iterador = iterador + 1
		}
	}
}