/*
 * AxisAlignedPlane.java
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
import java.awt.*;
import java.lang.Math;



public class AxisAlignedPlane implements Drawable {
	
	private static final Stroke stroke;
	private int index;
	private Point point;
	
	
	static {
		stroke = new DottedStroke();
	}
	
	
	/**
	 * Creates a new %AxisAlignedPlane.
	 * 
	 * @param point
	 *     Point on either the X or Y axis.
	 */
	public AxisAlignedPlane(Point point) throws Exception {
		
		// Copy
		this.point = point;
		
		// Set index
		if (point.x == 0.0) {
			index = 1;
		} else if (point.y == 0.0) {
			index = 0;
		} else {
			String message = "[AxisAlignedPlane] One component must be 0.";
			throw new Exception(message);
		}
	}
	
	
	/**
	 * Draws the plane as a line.
	 * 
	 * @param graphic
	 *     Graphic to draw into.
	 */
	public void draw(Graphics2D graphic,
	                 Dimension dimension) {
		
		// Set stroke
		graphic.setStroke(stroke);
		
		// Draw horizontal or vertical line
		if (point.x != 0.0)
			graphic.drawLine((int)point.x, 0, (int)point.x, dimension.height);
		else
			graphic.drawLine(0, (int)point.y, dimension.width, (int)point.y);
	}
	
	
	
	/**
	 * Returns a component of the vector by its index.
	 * 
	 * @param i
	 *     Index of the component.
	 */
	public double get(int i) {
		
		String message;
		
		switch (i) {
			case 0: 
				return point.x;
			case 1:
				return point.y;
			default:
				message = "[AxisAlignedPlane] Out of bounds.";
				throw new IndexOutOfBoundsException(message);
		}
	}
	
	
	
	/**
	 * Determines if the plane is intersected by a ray.
	 */
	public Intersection intersectedBy(Ray ray) {
		
		double di, pi, t;
		Point point;
		
		// Find ray direction component
		di = ray.direction.get(index);
		if (Math.abs(di) < 0.000000001)
			return null;
		
		// Find time it intersects
		pi = get(index) - ray.origin.get(index);
		t = pi / di;
		return ray.getIntersectionAt(t);
	}
	
	
	
	/**
	 * Test for the %AxisAlignedPlane.
	 */
	public static void main(String[] args) throws Exception {
		
		AxisAlignedPlane plane;
		Display display;
		Intersection intersection=null;
		Ray ray;
		
		// Start
		System.out.println();
		System.out.println("****************************************");
		System.out.println("AxisAlignedPlane");
		System.out.println("****************************************");
		System.out.println();
		
		// Create objects
		plane = new AxisAlignedPlane(new Point(20.0, 0.0));
		ray = new Ray(new Point(320.0, 240.0),      // origin
		              new Vector2D(-1.0, -0.6));    // direction
		
		// Test intersection
		intersection = plane.intersectedBy(ray);
		if (intersection != null) {
			ray.addIntersection(intersection);
		}
		
		// Display objects
		display = new Display("AxisAlignedPlane", 640, 480);
		display.add(plane);
		display.add(ray);
		display.start();
		
		// Finish
		System.out.println();
		System.out.println("****************************************");
		System.out.println("AxisAlignedPlane");
		System.out.println("****************************************");
		System.out.println();
	}
}
