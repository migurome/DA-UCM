import edu.princeton.cs.algs4.CC;
import edu.princeton.cs.algs4.Edge;
import edu.princeton.cs.algs4.EdgeWeightedGraph;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.PrimMST;

public class quince extends SolverJudgeA {

	public quince(String filename){
		super(SENTINEL, filename);
	}
	
	@Override
	public boolean solutionCase() {

		try {
			
			EdgeWeightedGraph dirigido = leerGrafo(new In(sc));

			CC componentes = new CC(dirigido);
			
			if(componentes.count() == 1) {
			PrimMST prim = new PrimMST(dirigido);
				out.println((int)prim.weight());

			}	
			else {				
				out.println("Imposible");
			}

		} catch (Exception e) {
			
			return true;
		}
		
		return false;
	}
	
	private EdgeWeightedGraph leerGrafo(In in) {
		
		EdgeWeightedGraph grafodirigido;
		
		int V = in.readInt();
		
		grafodirigido = new EdgeWeightedGraph(V);
		
        int E = in.readInt();
        if (E < 0) throw new IllegalArgumentException("Number of edges must be nonnegative");
        for (int i = 0; i < E; i++) {
            int v = in.readInt();
            int w = in.readInt();
            double weight = in.readDouble();
            Edge e = new Edge(v-1, w-1, weight);
            grafodirigido.addEdge(e);
        }
        
        return grafodirigido;
	}
}
