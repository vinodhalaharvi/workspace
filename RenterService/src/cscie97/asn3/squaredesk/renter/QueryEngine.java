/**
 * 
 */
package cscie97.asn3.squaredesk.renter;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Set;

/**
 * @author vinodhalaharvi
 *
 */
public class QueryEngine {

	/**
	 * 
	 */
	public QueryEngine() {
	}
	
	/**
	 * @param query
	 * @throws QueryEngineException
	 */
	public void executeQuery(String query) throws QueryEngineException {
		if (query == null){ 
			throw new QueryEngineException("Null query found"); 
		}
		//KnowledgeGraph.getInstance(); 
		System.out.println(query);
		for (Triple t: KnowledgeGraph.executeQuery(new Triple(query.trim()))){
			System.out.println(String.format("%s", t.getIdentifier())); 
		}
		System.out.println();
	}
	
	/**
	 * @param filename filepathname of the query file to execute
	 * @throws QueryEngineException
	 */
	@SuppressWarnings("resource")
	public void executeQueryFile(String filename) throws QueryEngineException {
		File file = new File(filename); 
		//KnowledgeGraph.getInstance(); 
		try {
			FileReader fr = new FileReader(file);
			BufferedReader input = new BufferedReader(fr);
			String line; 
			
			/*
			 * Read line by line, if any line has error then throw QueryEngineException
			 * call the KnowledgeGraph.executeQuery() on each line to execute the query
			 */
			try {
				while ((line = input.readLine()) != null) {
					line = line.replace('.', ' '); 
					line = line.trim(); 
					System.out.println(line);
					if (line.split(" ").length != 3) {
						throw new QueryEngineException("Not enough Query Arguements");
					} 					
					Set<Triple> temp = KnowledgeGraph.executeQuery(new Triple(line.trim()));
					if (temp != null){ 						
						for (Triple t: KnowledgeGraph.executeQuery(new Triple(line.trim()))){
							System.out.println(String.format("%s", t.getIdentifier())); 
						}
					} else { 
						System.out.println("<null>");
					}
					System.out.println();
				}
				input.close();
			} catch (IOException e) {
				e.printStackTrace();
				throw new QueryEngineException(); 
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			throw new QueryEngineException();
		} 
	}
}
