import bpy
import math
from math import sin, cos, pi

# ===============================
# SPRING CONFIGURATION
# ===============================

coil_radius = 0.02       # Radius of the spring (distance from center)
wire_radius = 0.005      # Thickness of the wire itself
coil_height = 0.10       # Total height of the spring
coil_turns = 8           # Number of spiral loops
resolution = 64          # Smoothness of the spiral

# ===============================
# MESH GENERATION
# ===============================

verts = []
edges = []
faces = []

# Generate spiral curve core
for i in range(resolution * coil_turns + 1):
    t = i / resolution
    angle = t * 2 * pi
    x = coil_radius * cos(angle)
    y = coil_radius * sin(angle)
    z = (coil_height / (coil_turns * 2 * pi)) * angle
    verts.append((x, y, z))

# Create mesh and object
mesh = bpy.data.meshes.new("SpringBase")
mesh.from_pydata(verts, [(i, i+1) for i in range(len(verts)-1)], [])
curve_obj = bpy.data.objects.new("SpringPath", mesh)
bpy.context.collection.objects.link(curve_obj)

# ===============================
# CONVERT PATH INTO ACTUAL SPRING
# ===============================

# Create a curve modifier object
bpy.ops.curve.primitive_bezier_circle_add(radius=wire_radius)
profile = bpy.context.active_object
profile.name = "SpringProfile"

# Convert the mesh path to a curve
bpy.context.view_layer.objects.active = curve_obj
bpy.ops.object.convert(target='CURVE')
curve = bpy.context.active_object
curve.data.bevel_object = profile
curve.data.fill_mode = 'FULL'
curve.data.resolution_u = 32

# ===============================
# CONVERT TO MESH
# ===============================

bpy.ops.object.convert(target='MESH')

# ===============================
# CLEANUP (Remove curve profile)
# ===============================

bpy.data.objects.remove(profile)

print("Spring mesh generated successfully!")
