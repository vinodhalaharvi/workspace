/*
 * 
 */
package cscie97.asn4.squaredesk.authentication;

/**
 * The Class PermissionVisitor.
 */
public abstract class PermissionVisitor {
        
        /**
         * Instantiates a new permission visitor.
         *
         * @param permission the permission
         */
        public PermissionVisitor(Permission permission) {
                super();
        }

        /**
         * Visit permission list.
         */
        public void visitPermissionList(){
                for(Permission permission : AuthenticationService.getPermissions()){
                        beforeVisitPermission(permission);
                        visitPermission(permission);
                        afterVisitPermission(permission);
                }
        }

        /**
         * Before visit permission.
         *
         * @param permission the permission
         */
        public void beforeVisitPermission(Permission permission) {
                System.out.println("Beginning permission Visit.. " + permission.getPermissionId());
        }

        /**
         * After visit permission.
         *
         * @param permission the permission
         */
        public void afterVisitPermission(Permission permission) {
                System.out.println("Ending permission Visit.. " + permission.getPermissionId());

        }

        /**
         * Visit permission.
         *
         * @param permission the permission
         */
        public void visitPermission(Permission permission) {
                //this is overridden by the client
                System.out.println("At permission visit.. " + permission.getPermissionId());
        }
}
