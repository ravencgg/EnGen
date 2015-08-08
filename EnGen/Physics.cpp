#include "Physics.h"


#if 0

bool check_collision(PhysicsRect& m, Vec2& velocity, PhysicsRect& other, CollisionData& out)
{
	bool result = false;
	Vec2 o = { m.col_rect.x + m.col_rect.w / 2.f, m.col_rect.y + m.col_rect.h / 2.f };

	Ray motion = { { o.x, o.y },
	{ o.x + velocity.x, o.y + velocity.y } };

	// Do the Minkowski sum
	Vec2 center = rect_center(other.col_rect);
	Rectf mSum = { other.col_rect.x - m.col_rect.w / 2.f,
		other.col_rect.y - m.col_rect.h / 2.f,
		m.col_rect.w + other.col_rect.w,
		m.col_rect.h + other.col_rect.h };

	Ray mRays[4] = {};
	Vec2 p[4] = { { mSum.x, mSum.y },
	{ mSum.x, mSum.y + mSum.h },
	{ mSum.x + mSum.w, mSum.y + mSum.h },
	{ mSum.x + mSum.w, mSum.y } };

	mRays[0] = make_ray(p[0], p[1]);
	mRays[1] = make_ray(p[1], p[2]);
	mRays[2] = make_ray(p[2], p[3]);
	mRays[3] = make_ray(p[3], p[0]);

	for (int i = 0; i < 4; ++i)
	{
		Vec2 e = motion.v1 - motion.v0;
		Vec2 f = mRays[i].v1 - mRays[i].v0;

		Vec2 p = { -e.y, e.x };

		float dfp = dot(f, p);

		if (dfp > 0)
		{
			float h = (dot(motion.v0 - mRays[i].v0, p) / dot(f, p));

			Vec2 impact = mRays[i].v0 + f * h;

			// TODO(cgenova): clean up this loop
			if (h > 0 && h < 1 && !result)
			{
				result = true;
				out.distance = length(impact - o);
				out.point = impact;
			}
			else if (h > 0 && h < 1)
			{
				float l = length(impact - o);
				if (out.distance > l)
				{
					out.distance = l;
					out.point = impact;
				}
			}
		}
	}
	return result;
}

// For detecting player/enemy or enemy/enemy collisions
// Does not return anything but the bool
//bool intersects()
//{
//	return false;
//}
#endif