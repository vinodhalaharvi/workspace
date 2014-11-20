/**
 * 
 */
package cscie97.asn3.squaredesk.renter;


// TODO: Auto-generated Javadoc
/**
 * The Class QueryEngine.
 */
public class QueryEngine {

	/**
	 * Instantiates a new query engine.
	 */
	public QueryEngine() {
	}
	
	/**
	 * Execute query.
	 *
	 * @param query the query
	 * @throws QueryEngineException the query engine exception
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
}
