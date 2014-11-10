/**
 * 
 */
package cscie97.asn3.squaredesk.renter;


/**
 * The Class QueryEngine.
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
}
