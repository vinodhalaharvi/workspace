/*
 * 
 */

package cscie97.asn4.squaredesk.authentication;

/**
 * The Class RoleVisitor.
 */
public abstract class RoleVisitor {
        
        /**
         * Instantiates a new role visitor.
         */
        public RoleVisitor() {
                super();
        }

        /**
         * Visit role list.
         */
        public void visitRoleList(){
                for(Role role : AuthenticationService.getRoles()){
                        beforeVisitRole(role);
                        visitRole(role);
                        afterVisitRole(role);
                        System.out.println();
                }		

        }

        /**
         * Before visit role.
         *
         * @param role the role
         */
        public void beforeVisitRole(Role role) {
                System.out.println("Beginning role Visit.. " + role.getRoleId());
        }

        /**
         * After visit role.
         *
         * @param role the role
         */
        public void afterVisitRole(Role role) {
                System.out.println("Ending role Visit.. " + role.getRoleId());

        }

        /**
         * Visit role.
         *
         * @param role the role
         */
        public void visitRole(Role role) {
                //this is overridden by the client
                System.out.println("At role visit.. " + role.getRoleId());
        }
}
