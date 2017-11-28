import edu.princeton.cs.algs4.BipartiteX;
import edu.princeton.cs.algs4.Graph;
import edu.princeton.cs.algs4.In;

public class diez extends SolverJudgeA {

	
	public diez(String filename){
		
		super(SENTINEL, filename);
		
	}
	
	@Override
	public boolean solutionCase() {
		
		try {
			Graph grafo = new Graph(new In(sc)); 
			
			// TODO Auto-generated method stub
			BipartiteX bipartito = new BipartiteX(grafo);
			
			if(bipartito.isBipartite())
				out.println("SI");
			else
				out.println("NO");
		} catch (Exception e) {
			// TODO Auto-generated catch block
			return true;
		}
		
		return false;
	}
}
