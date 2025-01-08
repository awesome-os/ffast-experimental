what we need is a modular runtime
this is the tool we use to run our apps locally and dynamically
this is the tool we use for building etc.
just the same as node, bun or deno today
these are all not modular

a big security problem is the fact that the runtime your deployed artifacts is running in
has a huge exposed surface area that is never used by any single application
these are all vectors for attack
the smaller the surface area, the more secure we are
if we could do tree-shaking and build a list of core dependencies as well as
JS/TS artifacts, then we could build a unique runtime for deployment that has
only the libraries and functions/classes used in it and nothing else

this would also have benefits of reducing memory usage, disk space etc.

you could take this even further by being able to build custom host runtimes which
can then be injected with a much smaller application payload to run

you can pre-bake these runtime configurations and have them on warm standby ready
to run the "applets"

