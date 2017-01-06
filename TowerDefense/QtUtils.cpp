#include "QtUtils.h"
#include <qmath.h>

int QtUtils::distance(const QPointF &a, const QPointF &b)
{
	return qSqrt((b.x() - a.x())*(b.x() - a.x()) + (b.y() - a.y())*(b.y() - a.y()));
}
