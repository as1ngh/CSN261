package app;
import java.io.File;
import java.io.IOException;
import java.util.Map;
import javax.imageio.ImageIO;
import com.mxgraph.layout.mxCircleLayout;
import com.mxgraph.layout.mxIGraphLayout;
import com.mxgraph.util.mxCellRenderer;
import org.jgrapht.graph.SimpleDirectedWeightedGraph;
import org.jgrapht.io.Attribute;
import org.jgrapht.io.EdgeProvider;
import org.jgrapht.io.GmlImporter;
import org.jgrapht.alg.scoring.*;
import org.jgrapht.io.ImportException;
import org.jgrapht.io.VertexProvider;
import org.jgrapht.ext.JGraphXAdapter;
import java.awt.image.*;
import java.awt.Color;

class UtilityObject{
	double[] dist ;
	int[] parent;
	UtilityObject(double[] dist, int[] parent){
		this.dist = dist;
		this.parent = parent;
	}
}
class UtilityObject2{
	int parents[][];
	int count;
	UtilityObject2(int[][] parents,int count){
		this.parents = parents;
		this.count = count;
	}
}
public class Q1 {
	public static int numberOfPaths(SimpleDirectedWeightedGraph<String, MyEdge> g,String v,double[] dist,int[] parent){
		int count=1;
		int V = g.vertexSet().size();
		Boolean[] path = new Boolean[V];
		makePath(parent, Integer.parseInt(v), path);
		int lengthOfPath=0;
		for(int i=0;i<V;i++){
			if(path[i]){
				lengthOfPath++;
			}
		}
		for(int u=0;u<V;u++){
			double d;
			try{
				d=g.getEdgeWeight(g.getEdge(v, Integer.toString(u)));
			}
			catch(Exception e){
				d=0;
			}
			if(d!=0){
				if((dist[Integer.parseInt(v)]==dist[u]+d)&&(parent[Integer.parseInt(v)]!=u)){
					count++;
				}
			}
		}
		return count;
	}
	public static void betweennessCentrality2(SimpleDirectedWeightedGraph<String, MyEdge> g){
		BetweennessCentrality<String,MyEdge> b = new BetweennessCentrality<String,MyEdge>(g);
		double d = b.getVertexScore(Integer.toString(3));
	}
	public static String minimumDistance(SimpleDirectedWeightedGraph<String, MyEdge> g, Boolean[] isVisited,double[] dist){
		double min=Integer.MAX_VALUE;
		String minDistanceVertex=Integer.toString(-1);
		int V = g.vertexSet().size();
		for(int v=0;v<V;v++){
			if (isVisited[v] == false && dist[v] <= min) { 
                min = dist[v]; 
				minDistanceVertex = Integer.toString(v);
			} 
		}
		return minDistanceVertex;
	}
        public static void betweennessCentrality(SimpleDirectedWeightedGraph<String, MyEdge> g){
		int V = g.vertexSet().size();
		for(int v=0;v<V;v++){
			for(int i=0;i<V;i++){
				for(int j=i+1;j<V;j++){
					if((i!=v)&&(j!=v)){
					}
				}
			}
		}	
	}
	public static Boolean[] shortestPathBetween(SimpleDirectedWeightedGraph<String, MyEdge> g,int from,int to ){
		dijkstraAlgorithm(g, from);
		return new Boolean[10];
	}
public static void printPath(int parent[], int j) { 
    if (parent[j] == - 1) 
        return; 
    printPath(parent, parent[j]); 
    System.out.print(j); 
}
public static void printSolution(SimpleDirectedWeightedGraph<String, MyEdge> g,double dist[],Boolean[][] paths,int parent[]) { 
		int V = g.vertexSet().size();
		int src = 0;
        System.out.println("Vertex \t\t Distance from Source"); 
		for (int i = 0; i < V; i++){ 
			System.out.printf("\n%d -> %d \t\t %f\t\t%d ", 
                      src, i, dist[i], src); 
        printPath(parent, i);
			
		}
	}
public static void makePath(int parent[],int j,Boolean[] path){
	if (parent[j] == - 1) 
		return;
	path[j]=true;
	makePath(parent,parent[j],path);
} 
	public static void dijkstraAlgorithm(SimpleDirectedWeightedGraph<String, MyEdge> g, int src){
		int V = g.vertexSet().size();
		double dist[] = new double[V];
		Boolean isVisited[] = new Boolean[V];
		int parent[]=new int[V];  
        for (int i = 0; i < V; i++) { 
            dist[i] = Integer.MAX_VALUE; 
			isVisited[i] = false;
			parent[0]=-1; 
        } 
		Boolean[][] paths = new Boolean[V][V];
		for(int i =0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				paths[i][j]=false;
			}
		}
        dist[src] = 0; 
        for (int count = 0; count < V - 1; count++) { 
            int u = Integer.parseInt(minimumDistance(g, isVisited, dist));
            isVisited[u] = true; 
            for (int v = 0; v < V; v++) {
				double d;
				try{ 
				 d = g.getEdgeWeight(g.getEdge(Integer.toString(u),Integer.toString(v)));}
				catch(Exception e)
				{
					d=0;
				}
                if (!isVisited[v] && d != 0 && dist[u] != Integer.MAX_VALUE && dist[u] + d < dist[v]){ 
					parent[v] = u; 
					dist[v] = dist[u] + d;
					

				} 
        }	
	} 
	printSolution(g,dist,paths,parent);
	UtilityObject utilityObject = new UtilityObject(dist, parent);
	}
public static SimpleDirectedWeightedGraph<String, MyEdge> readGraph() {
		SimpleDirectedWeightedGraph<String, MyEdge>  g = 
            new SimpleDirectedWeightedGraph<String, MyEdge>
            (MyEdge.class);

		VertexProvider<String> vp = new VertexProvider<String>() {

			@Override
			public String buildVertex(String arg0, Map<String, Attribute> arg1) {
				return arg0;
			}
			};
		

		EdgeProvider<String, MyEdge> ep = new EdgeProvider<String, MyEdge>() {
			@Override
			public MyEdge buildEdge(String arg0, String arg1, String arg2, Map<String, Attribute> arg3) {
				//g.setEdgeWeight(arg0, arg1, g.DEFAULT_EDGE_WEIGHT);
				MyEdge myEdge = g.addEdge(arg0, arg1);
				return myEdge;
				
			}
		};
		File file = new File("src/app/graph.gml");
		GmlImporter<String,MyEdge> importer = new GmlImporter<String,MyEdge>(vp, ep);
		try {
			importer.importGraph(g,file );
		} catch (ImportException e) {
			System.out.println("failed");
		}
		return g;
}
public static void writeGraph(SimpleDirectedWeightedGraph<String, MyEdge> g)
{
	JGraphXAdapter<String, MyEdge> graphAdapter = new JGraphXAdapter<String, MyEdge>(g);
		mxIGraphLayout layout = new mxCircleLayout(graphAdapter);
		layout.execute(graphAdapter.getDefaultParent());

		BufferedImage image = mxCellRenderer.createBufferedImage(graphAdapter, null, 2, Color.white, true, null);
		File imgFile = new File("graph.png");
		try {
			ImageIO.write(image, "PNG", imgFile);
		} catch (IOException e1) {
			e1.printStackTrace();
		}
}

	public static void main(String[] args) {
		SimpleDirectedWeightedGraph<String, MyEdge> g = readGraph();
		dijkstraAlgorithm(g, 0);
		writeGraph(g);
		
		}	
	}
	
	
	

