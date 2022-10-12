import java.util.*;

class Main{
	public static void main(String[] args){
		int cases, n, temp, max_el;
		Scanner s = new Scanner(System.in);

		cases = s.nextInt();

		for(int i = 1; i <= cases; i++){
			Vector <Integer> vec1 = new Vector <Integer>();
			Vector <Integer> vec2 = new Vector <Integer>();
			Vector <Integer> vec3 = new Vector <Integer>();
			Vector <Integer> ans1 = new Vector <Integer>();
			Vector <Integer> ans2 = new Vector <Integer>();
			Vector <Integer> ans3 = new Vector <Integer>();
			Vector <Integer> res = new Vector <Integer>();
			Vector <Integer> ans = new Vector <>();
			ans.add(0);
			ans.add(0);
			ans.add(0);
			res.add(0);
			res.add(0);
			res.add(0);

			for(int j = 0; j < 10001; j++){
				vec1.add(0);
				vec2.add(0);
				vec3.add(0);
			}

			n = s.nextInt();

			for(int j = 0; j < n; j++){
				temp = s.nextInt();
				vec1.set(temp, 1);
			}

			n = s.nextInt();

			for(int j = 0; j < n; j++){
				temp = s.nextInt();
				vec2.set(temp, 1);
			}

			n = s.nextInt();

			for(int j = 0; j < n; j++){
				temp = s.nextInt();
				vec3.set(temp, 1);
			}

			for(int j = 0; j < 10001; j++){
				if(vec1.get(j) == 1 && vec2.get(j) == 0 && vec3.get(j) == 0){
					ans1.add(j);
					ans.set(0, ans.get(0) + 1);
				}
				if(vec1.get(j) == 0 && vec2.get(j) == 1 && vec3.get(j) == 0){
					ans2.add(j);
					ans.set(1, ans.get(1) + 1);
				}
				if(vec1.get(j) == 0 && vec2.get(j) == 0 && vec3.get(j) == 1){
					ans3.add(j);
					ans.set(2, ans.get(2) + 1);
				}
			}

			max_el = Collections.max(ans);

			for(int j = 0; j < 3; j++)
				if(ans.get(j) == max_el)
					res.set(j, 1);

			System.out.println("Case #" + i + ":");
			
			if(res.get(0) == 1){
				System.out.printf(1 + " " + max_el);
				for(int j = 0; j < max_el; j++){
					System.out.printf(" " + ans1.get(j));
				}
				System.out.println();
			}
			if(res.get(1) == 1){
				System.out.printf(2 + " " + max_el);
				for(int j = 0; j < max_el; j++){
					System.out.printf(" " + ans2.get(j));
				}
				System.out.println();
			}
			if(res.get(2) == 1){
				System.out.printf(3 + " " + max_el);
				for(int j = 0; j < max_el; j++){
					System.out.printf(" " + ans3.get(j));
				}
				System.out.println();
			}

		}
	}
}