import java.io.*; 
import java.util.*; 

class Main{
	public static void main(String args[]){
		int n, temp, cases;

		Scanner s = new Scanner(System.in);
		
		cases = s.nextInt();

		for(int i = 1; i <= cases; i++){
			Vector<Integer> vec = new Vector<Integer>();
			n = s.nextInt();
			int hi = 0, lo = 0;

			for(int j = 0; j < n; j++){
				temp = s.nextInt();
				vec.add(temp);
			}

			for(int j = 1; j < n; j++){
				if(vec.get(j) > vec.get(j - 1)){
					hi++;
				}
				else if(vec.get(j) < vec.get(j - 1)){
					lo++;
				}
			}

			System.out.println("Case " + i + ": " + hi + " " + lo);
		}

	}
}